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
		virtual void insert_device(const Slot *, Device *) override;

		private:
		const Component * const top_level_component_;
		std::map<const Slot *, Device *> slot_device_map_;
	};

} // test
} // model

#endif