include(CMakeFindDependencyMacro)

if ()
  find_dependency(OpenGL)
endif()
find_dependency(Eigen3)

# Find spdlog if g2o was build with support for it
if ()
  find_dependency(spdlog)
endif()

include("${CMAKE_CURRENT_LIST_DIR}/g2oTargets.cmake")
