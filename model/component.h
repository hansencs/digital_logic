#ifndef MODEL__COMPONENT_H_
#define MODEL__COMPONENT_H_

#include <vector>

#include "pin_factory.h"

namespace model {

	class Component {
		public:
		Component(
			const std::string &name,
			const std::vector<std::string> &input_names,
			const std::vector<std::string> &output_names,
			const PinFactory *
		);
		Component(
			const std::string &name,
			const std::vector<std::string> &input_names,
			const std::vector<std::string> &output_names
		);
		~Component(void);
		const std::string &name(void) const;
		const std::vector<InputPin *> &input_pins(void) const;
		const InputPin *get_input_pin(unsigned index) const;
		const InputPin *get_input_pin(std::string name) const;
		const std::vector<OutputPin *> &output_pins(void) const;
		const OutputPin *get_output_pin(unsigned index) const;
		const OutputPin *get_output_pin(std::string name) const;

		private:
		std::string name_;
		std::vector<InputPin *> inputs_; // owned
		std::vector<OutputPin *> outputs_; // owned

		static constexpr class : public PinFactory {
			public:
			virtual InputPin *make_input_pin(
				Component *component,
				std::string name
			) const {
				return new InputPin(name, component);
			}
			virtual OutputPin *make_output_pin(
				Component *component,
				std::string name
			) const {
				return new OutputPin(name, component);
			}
		} component_pin_factory;
	};

} // model

#endif