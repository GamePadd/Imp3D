set(SOURCES 
	"OnixEngine.cpp"
)
set(HEADERS
	"OnixEngine.h"
)

file(
	COPY ${CMAKE_SOURCE_DIR}/OnixEngine/shaders
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable (OnixEngine ${SOURCES} ${HEADERS} ${GLAD_DIR}/src/glad.c)

target_include_directories(OnixEngine PUBLIC ${GLAD_DIR}/include)
target_link_libraries(OnixEngine PRIVATE glfw)