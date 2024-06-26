#ifndef MODEL__TEST_MODEL__TEST_MODEL_HPP_
#define MODEL__TEST_MODEL__TEST_MODEL_HPP_

#include <map>

#include "model.hpp"

namespace model {

class Component;

namespace test {

	class TestModel : public Model {
		public:
		TestModel(const Component *top_level_component);
		virtual const Component *top_level_component(void) const override;
		const Component *top_level_component_;
	};

} // test
} // model

#endif