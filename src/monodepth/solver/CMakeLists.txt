add_library(solver STATIC solver_build.cpp lr_scheduler.cpp optimizer.cpp)
target_include_directories(solver 
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../include/monodepth/solver/)
target_link_libraries(solver PUBLIC ${TORCH_LIBRARIES} config utils modeling)