# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "main_controller: 0 messages, 12 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(main_controller_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/turnRight.srv" NAME_WE)
add_custom_target(_main_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "main_controller" "/home/rosbox/control_code/src/main_controller/srv/turnRight.srv" ""
)

get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/moveReverse.srv" NAME_WE)
add_custom_target(_main_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "main_controller" "/home/rosbox/control_code/src/main_controller/srv/moveReverse.srv" ""
)

get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/longRateUp.srv" NAME_WE)
add_custom_target(_main_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "main_controller" "/home/rosbox/control_code/src/main_controller/srv/longRateUp.srv" ""
)

get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/moveUp.srv" NAME_WE)
add_custom_target(_main_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "main_controller" "/home/rosbox/control_code/src/main_controller/srv/moveUp.srv" ""
)

get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/turnLeft.srv" NAME_WE)
add_custom_target(_main_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "main_controller" "/home/rosbox/control_code/src/main_controller/srv/turnLeft.srv" ""
)

get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/longRateFull.srv" NAME_WE)
add_custom_target(_main_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "main_controller" "/home/rosbox/control_code/src/main_controller/srv/longRateFull.srv" ""
)

get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/allStop.srv" NAME_WE)
add_custom_target(_main_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "main_controller" "/home/rosbox/control_code/src/main_controller/srv/allStop.srv" ""
)

get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/setMotor.srv" NAME_WE)
add_custom_target(_main_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "main_controller" "/home/rosbox/control_code/src/main_controller/srv/setMotor.srv" ""
)

get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/longRateReset.srv" NAME_WE)
add_custom_target(_main_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "main_controller" "/home/rosbox/control_code/src/main_controller/srv/longRateReset.srv" ""
)

get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/moveForward.srv" NAME_WE)
add_custom_target(_main_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "main_controller" "/home/rosbox/control_code/src/main_controller/srv/moveForward.srv" ""
)

get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/moveDown.srv" NAME_WE)
add_custom_target(_main_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "main_controller" "/home/rosbox/control_code/src/main_controller/srv/moveDown.srv" ""
)

get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/longRateDown.srv" NAME_WE)
add_custom_target(_main_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "main_controller" "/home/rosbox/control_code/src/main_controller/srv/longRateDown.srv" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/turnRight.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_controller
)
_generate_srv_cpp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/moveReverse.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_controller
)
_generate_srv_cpp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/longRateUp.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_controller
)
_generate_srv_cpp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/moveUp.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_controller
)
_generate_srv_cpp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/turnLeft.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_controller
)
_generate_srv_cpp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/longRateFull.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_controller
)
_generate_srv_cpp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/allStop.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_controller
)
_generate_srv_cpp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/setMotor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_controller
)
_generate_srv_cpp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/longRateReset.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_controller
)
_generate_srv_cpp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/moveForward.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_controller
)
_generate_srv_cpp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/moveDown.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_controller
)
_generate_srv_cpp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/longRateDown.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_controller
)

### Generating Module File
_generate_module_cpp(main_controller
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_controller
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(main_controller_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(main_controller_generate_messages main_controller_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/turnRight.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_cpp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/moveReverse.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_cpp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/longRateUp.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_cpp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/moveUp.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_cpp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/turnLeft.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_cpp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/longRateFull.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_cpp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/allStop.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_cpp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/setMotor.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_cpp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/longRateReset.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_cpp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/moveForward.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_cpp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/moveDown.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_cpp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/longRateDown.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_cpp _main_controller_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(main_controller_gencpp)
add_dependencies(main_controller_gencpp main_controller_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS main_controller_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/turnRight.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_controller
)
_generate_srv_lisp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/moveReverse.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_controller
)
_generate_srv_lisp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/longRateUp.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_controller
)
_generate_srv_lisp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/moveUp.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_controller
)
_generate_srv_lisp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/turnLeft.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_controller
)
_generate_srv_lisp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/longRateFull.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_controller
)
_generate_srv_lisp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/allStop.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_controller
)
_generate_srv_lisp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/setMotor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_controller
)
_generate_srv_lisp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/longRateReset.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_controller
)
_generate_srv_lisp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/moveForward.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_controller
)
_generate_srv_lisp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/moveDown.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_controller
)
_generate_srv_lisp(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/longRateDown.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_controller
)

### Generating Module File
_generate_module_lisp(main_controller
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_controller
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(main_controller_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(main_controller_generate_messages main_controller_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/turnRight.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_lisp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/moveReverse.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_lisp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/longRateUp.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_lisp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/moveUp.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_lisp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/turnLeft.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_lisp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/longRateFull.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_lisp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/allStop.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_lisp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/setMotor.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_lisp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/longRateReset.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_lisp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/moveForward.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_lisp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/moveDown.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_lisp _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/longRateDown.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_lisp _main_controller_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(main_controller_genlisp)
add_dependencies(main_controller_genlisp main_controller_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS main_controller_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/turnRight.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_controller
)
_generate_srv_py(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/moveReverse.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_controller
)
_generate_srv_py(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/longRateUp.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_controller
)
_generate_srv_py(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/moveUp.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_controller
)
_generate_srv_py(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/turnLeft.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_controller
)
_generate_srv_py(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/longRateFull.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_controller
)
_generate_srv_py(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/allStop.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_controller
)
_generate_srv_py(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/setMotor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_controller
)
_generate_srv_py(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/longRateReset.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_controller
)
_generate_srv_py(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/moveForward.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_controller
)
_generate_srv_py(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/moveDown.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_controller
)
_generate_srv_py(main_controller
  "/home/rosbox/control_code/src/main_controller/srv/longRateDown.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_controller
)

### Generating Module File
_generate_module_py(main_controller
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_controller
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(main_controller_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(main_controller_generate_messages main_controller_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/turnRight.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_py _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/moveReverse.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_py _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/longRateUp.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_py _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/moveUp.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_py _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/turnLeft.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_py _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/longRateFull.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_py _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/allStop.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_py _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/setMotor.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_py _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/longRateReset.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_py _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/moveForward.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_py _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/moveDown.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_py _main_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/main_controller/srv/longRateDown.srv" NAME_WE)
add_dependencies(main_controller_generate_messages_py _main_controller_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(main_controller_genpy)
add_dependencies(main_controller_genpy main_controller_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS main_controller_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_controller)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_controller
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(main_controller_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_controller)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_controller
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(main_controller_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_controller)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_controller\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_controller
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(main_controller_generate_messages_py std_msgs_generate_messages_py)
