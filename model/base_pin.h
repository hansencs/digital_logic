#ifndef MODEL__PIN_H_
#define MODEL__PIN_H_

#include <string>

namespace model {

	class Component;

	namespace base_pin {

		class BasePin {
			public:
			const Component *component(void) const;
			const std::string &name(void) const;

			protected:
			std::string name_;
			const Component *component_;
		};

	} // base_pin

} // model

#endif