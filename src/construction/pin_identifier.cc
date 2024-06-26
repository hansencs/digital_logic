#include "pin_identifier.h"

using namespace construction;
using namespace std;

PinIdentifier PinIdentifier::make_interior(
	const std::string &component_name,
	PinIdentifierType pin_type,
	const std::string &pin_name
) {
	return PinIdentifier(component_name, pin_type, pin_name);
}

PinIdentifier PinIdentifier::make_interior(
	const std::string &component_name,
	PinIdentifierType pin_type,
	unsigned pin_index
) {
	return PinIdentifier(component_name, pin_type, pin_index);
}

PinIdentifier PinIdentifier::make_exterior(
	PinIdentifierType pin_type,
	const std::string &pin_name
) {
	return PinIdentifier({}, pin_type, pin_name);
}

PinIdentifier PinIdentifier::make_exterior(
	PinIdentifierType pin_type,
	unsigned pin_index
) {
	return PinIdentifier({}, pin_type, pin_index);
}

PinIdentifierType PinIdentifier::pin_type(void) const {
	return pin_type_;
}

bool PinIdentifier::is_interior(void) const {
	return component_name_.has_value();
}

const std::string &PinIdentifier::component_name(void) {
	if (!is_interior()) throw string("identifier has no component name");
	return *component_name_;
}

bool PinIdentifier::has_pin_name(void) const {
	return pin_name_.has_value();
}

const std::string &PinIdentifier::pin_name(void) const {
	if (!has_pin_name()) throw string("identifier has no pin name");
	return *pin_name_;
}

unsigned PinIdentifier::pin_index(void) const {
	if (has_pin_name()) throw string("identifer has no pin index");
	return *pin_index_;
}

PinIdentifier::PinIdentifier(
	const std::optional<std::string> &component_name,
	PinIdentifierType pin_type,
	const std::string &pin_name
) :
	pin_type_(pin_type),
	component_name_(component_name),
	pin_name_(pin_name),
	pin_index_()
{}

PinIdentifier::PinIdentifier(
	const std::optional<std::string> &component_name,
	PinIdentifierType pin_type,
	unsigned pin_index
) :
	pin_type_(pin_type),
	component_name_(component_name),
	pin_name_(),
	pin_index_(pin_index)
{}