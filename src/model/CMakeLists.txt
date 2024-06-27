add_library(
	model
	circuit.cc
	nand.cc
	slot.cc
)
target_include_directories(
	model
	PUBLIC
	"${PROJECT_SOURCE_DIR}/src/model"
)

add_subdirectory(testing)