#ifndef MODEL__TESTING__TEST_PIN_HPP_
#define MODEL__TESTING__TEST_PIN_HPP_

#include "pin.hpp"

namespace model {
namespace test {

	class TestWire;

	class TestPin : public Pin {
		public:
		TestPin(Component *, std::string name);
		virtual const Component *component(void) const;
		virtual const Wire *wire(void) const;
		virtual const std::string &name(void) const;
		void set_wire(TestWire *);

		private:
		Component *component_;
		TestWire *wire_;
		const std::string name_;
	};

} // test
} // model

#endif