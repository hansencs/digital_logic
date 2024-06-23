#ifndef MODEL__TEST_MODEL__TEST_MODEL_H_
#define MODEL__TEST_MODEL__TEST_MODEL_H_

#include <map>

#include "model.h"

namespace model {

class Component;

namespace test {

	class TestModel : public Model {
		public:
		TestModel(const Component *top_level_component);

		private:
		const Component * const top_level_component_;
	};

} // test
} // model

#endif