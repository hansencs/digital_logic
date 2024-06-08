#ifndef CONSTRUCTION__PIN_IDENTIFIER_H_
#define CONSTRUCTION__PIN_IDENTIFIER_H_

#include <optional>
#include <string>

namespace construction {
	
	enum PinIdentifierType {
		INPUT,
		OUTPUT
	};

	class PinIdentifier {
		public:
		static PinIdentifier make_interior(
			const std::string &component_name,
			PinIdentifierType pin_type,
			const std::string &pin_name
		);
		static PinIdentifier make_interior(
			const std::string &component_name,
			PinIdentifierType pin_type,
			unsigned pin_index
		);
		static PinIdentifier make_exterior(
			PinIdentifierType pin_type,
			const std::string &pin_name
		);
		static PinIdentifier make_exterior(
			PinIdentifierType pin_type,
			unsigned pin_index
		);
		PinIdentifierType pin_type(void) const;
		bool is_interior(void) const;
		const std::string &component_name(void);
		bool has_pin_name(void) const;
		const std::string &pin_name(void) const;
		unsigned pin_index(void) const;

		private:
		PinIdentifier(
			const std::optional<std::string> &component_name,
			PinIdentifierType pin_type,
			const std::string &pin_name
		);
		PinIdentifier(
			const std::optional<std::string> &component_name,
			PinIdentifierType pin_type,
			unsigned pin_index
		);
		const PinIdentifierType pin_type_;
		const std::optional<std::string> component_name_;
		const std::optional<std::string> pin_name_;
		const std::optional<unsigned> pin_index_;
	};

} // construction

#endif