#ifndef MODEL__PIN_HPP_
#define MODEL__PIN_HPP_

#include <string>

namespace model {

	class Component;
	class Wire;

	class Pin {
		public:
		virtual const Component *component(void) const = 0;
		virtual const std::string &name(void) const = 0;
		virtual ~Pin(void) {};
	};

} // model

#endif