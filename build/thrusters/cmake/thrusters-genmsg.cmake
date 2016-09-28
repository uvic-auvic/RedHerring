# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "thrusters: 3 messages, 0 services")

set(MSG_I_FLAGS "-Ithrusters:/home/rosbox/control_code/src/thrusters/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(thrusters_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/rosbox/control_code/src/thrusters/msg/Sensitivity.msg" NAME_WE)
add_custom_target(_thrusters_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "thrusters" "/home/rosbox/control_code/src/thrusters/msg/Sensitivity.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/rosbox/control_code/src/thrusters/msg/thrusterTemperatures.msg" NAME_WE)
add_custom_target(_thrusters_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "thrusters" "/home/rosbox/control_code/src/thrusters/msg/thrusterTemperatures.msg" ""
)

get_filename_component(_filename "/home/rosbox/control_code/src/thrusters/msg/thrusterValues.msg" NAME_WE)
add_custom_target(_thrusters_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "thrusters" "/home/rosbox/control_code/src/thrusters/msg/thrusterValues.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(thrusters
  "/home/rosbox/control_code/src/thrusters/msg/Sensitivity.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/thrusters
)
_generate_msg_cpp(thrusters
  "/home/rosbox/control_code/src/thrusters/msg/thrusterTemperatures.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/thrusters
)
_generate_msg_cpp(thrusters
  "/home/rosbox/control_code/src/thrusters/msg/thrusterValues.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/thrusters
)

### Generating Services

### Generating Module File
_generate_module_cpp(thrusters
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/thrusters
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(thrusters_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(thrusters_generate_messages thrusters_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rosbox/control_code/src/thrusters/msg/Sensitivity.msg" NAME_WE)
add_dependencies(thrusters_generate_messages_cpp _thrusters_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/thrusters/msg/thrusterTemperatures.msg" NAME_WE)
add_dependencies(thrusters_generate_messages_cpp _thrusters_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/thrusters/msg/thrusterValues.msg" NAME_WE)
add_dependencies(thrusters_generate_messages_cpp _thrusters_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(thrusters_gencpp)
add_dependencies(thrusters_gencpp thrusters_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS thrusters_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(thrusters
  "/home/rosbox/control_code/src/thrusters/msg/Sensitivity.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/thrusters
)
_generate_msg_lisp(thrusters
  "/home/rosbox/control_code/src/thrusters/msg/thrusterTemperatures.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/thrusters
)
_generate_msg_lisp(thrusters
  "/home/rosbox/control_code/src/thrusters/msg/thrusterValues.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/thrusters
)

### Generating Services

### Generating Module File
_generate_module_lisp(thrusters
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/thrusters
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(thrusters_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(thrusters_generate_messages thrusters_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rosbox/control_code/src/thrusters/msg/Sensitivity.msg" NAME_WE)
add_dependencies(thrusters_generate_messages_lisp _thrusters_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/thrusters/msg/thrusterTemperatures.msg" NAME_WE)
add_dependencies(thrusters_generate_messages_lisp _thrusters_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/thrusters/msg/thrusterValues.msg" NAME_WE)
add_dependencies(thrusters_generate_messages_lisp _thrusters_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(thrusters_genlisp)
add_dependencies(thrusters_genlisp thrusters_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS thrusters_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(thrusters
  "/home/rosbox/control_code/src/thrusters/msg/Sensitivity.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/thrusters
)
_generate_msg_py(thrusters
  "/home/rosbox/control_code/src/thrusters/msg/thrusterTemperatures.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/thrusters
)
_generate_msg_py(thrusters
  "/home/rosbox/control_code/src/thrusters/msg/thrusterValues.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/thrusters
)

### Generating Services

### Generating Module File
_generate_module_py(thrusters
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/thrusters
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(thrusters_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(thrusters_generate_messages thrusters_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rosbox/control_code/src/thrusters/msg/Sensitivity.msg" NAME_WE)
add_dependencies(thrusters_generate_messages_py _thrusters_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/thrusters/msg/thrusterTemperatures.msg" NAME_WE)
add_dependencies(thrusters_generate_messages_py _thrusters_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/thrusters/msg/thrusterValues.msg" NAME_WE)
add_dependencies(thrusters_generate_messages_py _thrusters_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(thrusters_genpy)
add_dependencies(thrusters_genpy thrusters_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS thrusters_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/thrusters)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/thrusters
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(thrusters_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/thrusters)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/thrusters
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(thrusters_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/thrusters)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/thrusters\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/thrusters
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(thrusters_generate_messages_py std_msgs_generate_messages_py)
