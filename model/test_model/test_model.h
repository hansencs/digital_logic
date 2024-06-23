#ifndef MODEL__TEST_MODEL__TEST_MODEL_H_
#define MODEL__TEST_MODEL__TEST_MODEL_H_

#include "model.h"

namespace model {

class Component;

namespace test {

	class TestModel : public Model {
		public:
		TestModel(const Component *top_level_component);

		private:
		const Component *top_level_component_;
	};

} // test
} // model

#endif