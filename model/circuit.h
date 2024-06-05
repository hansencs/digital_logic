#ifndef MODEL__CIRCUIT_H_
#define MODEL__CIRCUIT_H_

#include <map>
#include <vector>

#include "component.h"
#include "dual_pin.h"
#include "pin_factory.h"

namespace model {

	class Circuit : public Component {
		public:
		Circuit(
			const std::string &name,
			const std::map<std::string, const Component *> children,
			const std::vector<std::string> &input_names,
			const std::vector<std::string> &output_names
		);
		const Component *get_component(std::string name) const;
		const DualPin *get_input_pin(unsigned index) const;
		const DualPin *get_input_pin(std::string name) const;
		const DualPin *get_output_pin(unsigned index) const;
		const DualPin *get_output_pin(std::string name) const;

		private:
		const std::map<std::string, const Component *> children_;

		static constexpr class : public PinFactory {
			public:
			virtual InputPin *make_input_pin(
				Component *component,
				std::string name
			) const {
				return new DualPin(name, component);
			}
			virtual OutputPin *make_output_pin(
				Component *component,
				std::string name
			) const {
				return new DualPin(name, component);
			}
		} circuit_pin_factory;
	};

} // model

#endif