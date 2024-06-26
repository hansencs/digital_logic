#ifndef MODEL__TESTING__TEST_PIN_HPP_
#define MODEL__TESTING__TEST_PIN_HPP_

#include "input_pin.hpp"
#include "output_pin.hpp"

namespace model {
namespace test {

	class TestWire;

	class TestPin : public InputPin, public OutputPin {
		public:
		TestPin(Component *, std::string name);
		virtual const Component *component(void) const override;
		virtual const Wire *input_wire(void) const override;
		virtual std::optional<const Wire *> output_wire(void) const override;
		virtual const std::string &name(void) const override;
		void set_wire(TestWire *);

		private:
		Component *component_;
		TestWire *wire_;
		const std::string name_;
	};

} // test
} // model

#endif