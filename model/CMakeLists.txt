add_library(
	model
	placeholder.cc
)
target_include_directories(
	model
	PUBLIC
	"${PROJECT_SOURCE_DIR}/model"
)

add_subdirectory(test_model)