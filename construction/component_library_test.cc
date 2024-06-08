#include <gtest/gtest.h>

#include "component.h"
#include "component_library.h"
#include "test_component_spec.h"

#define MOVE(p) { TestComponentSpec *t = (p); (p) = nullptr; t; }

using namespace construction;
using namespace model;
using namespace std;

class ComponentLibraryTest : public testing::Test {
	protected:
	Component *c1 = new Component("c1", {}, {});
	Component *c2 = new Component("c2", {}, {});
	TestComponentSpec *s1 = new TestComponentSpec("s1", c1);
	TestComponentSpec *dups1 = new TestComponentSpec("s1", c2);
	ComponentLibrary cl;
	ComponentSpec *movep(TestComponentSpec **p) {
		ComponentSpec *t = *p;
		*p = nullptr;
		return t;
	}
	~ComponentLibraryTest(void) {
		if (s1) delete s1;
		if (dups1) delete dups1;
	}
};

TEST_F(ComponentLibraryTest, ProduceNoSpec) {
	EXPECT_THROW(cl.produce("I'm not real!", "_"), string); 
}

TEST_F(ComponentLibraryTest, AddExistingName) {
	cl.add_spec(movep(&s1));
	EXPECT_THROW(cl.add_spec(dups1), string);
}

TEST_F(ComponentLibraryTest, Produce) {
	cl.add_spec(movep(&s1));

	EXPECT_EQ(cl.produce("s1", "_"), c1);
}