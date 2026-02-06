set(SOURCES 
	"Imp3D.cpp"
	"ECS_World/Entities.cpp"
	"ECS_World/ComponentBase.cpp"
	"ECS_World/ComponentClass.cpp"
	"ECS_World/Systems.cpp"
	"ECS_World/World.cpp"
	"ConsoleLogger.cpp"
)

set(HEADERS
	"Imp3D.h"
	"ECS_World/Entities.h"
	"ECS_World/ComponentBase.h"
	"ECS_World/ComponentClass.h"
	"ECS_World/Systems.h"
	"ECS_World/World.cpp"
	"ConsoleLogger.h"
)

file(
	COPY ${CMAKE_SOURCE_DIR}/Imp3D/shaders
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable (Imp3D ${SOURCES} ${HEADERS} ${GLAD_DIR}/src/glad.c ${STB_DIR}/stb_image.h)

target_include_directories(Imp3D PUBLIC ${GLAD_DIR}/include)
target_include_directories(Imp3D PUBLIC ${STB_DIR})

target_link_libraries(Imp3D PRIVATE glfw)
target_link_libraries(Imp3D PRIVATE glm)