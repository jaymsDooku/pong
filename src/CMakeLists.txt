add_executable(${PROJECT_NAME} texture.h texture.c text.h text.c timer.h timer.c paddle.h paddle.c ball.h ball.c button.h button.c app.h app.c game.h game.c menu.h menu.c sdl_data.h sdl_data.c app_state.h app_state.c)
target_sources(${PROJECT_NAME} PRIVATE main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)

FILE(COPY img DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
FILE(COPY fonts DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")