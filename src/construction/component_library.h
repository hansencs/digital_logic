#ifndef CONSTRUCTION__COMPONENT_LIBRARY_H_
#define CONSTRUCTION__COMPONENT_LIBRARY_H_

#include <map>
#include <string>

namespace model {

	class Component;

} // model

namespace construction {

	class ComponentSpec;

	class ComponentLibrary {
		public:
		void add_spec(const ComponentSpec *);
		model::Component *produce(
			const std::string &spec_name,
			const std::string &component_name
		) const;
		~ComponentLibrary(void);
		
		private:
		std::map<std::string, const ComponentSpec *> library_; // owned
	};

} // construction

#endif