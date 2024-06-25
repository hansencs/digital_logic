#ifndef MODEL__MODEL_H_
#define MODEL__MODEL_H_

namespace model {

	class Component;

	class Model {
		public:
		virtual const Component *top_level_component(void) const = 0;
	};

} // model

#endif