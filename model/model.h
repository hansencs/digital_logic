#ifndef MODEL__MODEL_H_
#define MODEL__MODEL_H_

namespace model {

	class Device;
	class Slot;

	class Model {
		public:
		virtual void insert_device(const Slot *, Device *) = 0;
	};

} // model

#endif