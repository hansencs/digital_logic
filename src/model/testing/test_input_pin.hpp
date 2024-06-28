#ifndef MODEL__TESTING__TEST_INPUT_PIN_HPP_
#define MODEL__TESTING__TEST_INPUT_PIN_HPP_

#include "input_pin.hpp"
#include "output_pin.hpp"

namespace model {
namespace test {

	class TestWire;

	class TestInputPin : public InputPin {
		public:
		TestInputPin(Component *, std::string name);
		TestInputPin(Component *, std::string name, const OutputPin *dual);
		virtual const Component *component(void) const override;
		virtual const Wire *input_wire(void) const override;
		virtual std::optional<const OutputPin *> dual(void) const override;
		virtual const std::string &name(void) const override;
		void set_wire(TestWire *);

		private:
		Component *component_;
		TestWire *wire_;
		const std::string name_;
		std::optional<const OutputPin *> dual_;
	};

} // test
} // model

#endif