# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "imu_int: 1 messages, 1 services")

set(MSG_I_FLAGS "-Iimu_int:/home/rosbox/control_code/src/imu_int/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Iimu_int:/home/rosbox/control_code/src/imu_int/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(imu_int_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/rosbox/control_code/src/imu_int/srv/ImuIntCommand.srv" NAME_WE)
add_custom_target(_imu_int_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "imu_int" "/home/rosbox/control_code/src/imu_int/srv/ImuIntCommand.srv" ""
)

get_filename_component(_filename "/home/rosbox/control_code/src/imu_int/msg/IMU_Int_Data.msg" NAME_WE)
add_custom_target(_imu_int_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "imu_int" "/home/rosbox/control_code/src/imu_int/msg/IMU_Int_Data.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(imu_int
  "/home/rosbox/control_code/src/imu_int/msg/IMU_Int_Data.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/imu_int
)

### Generating Services
_generate_srv_cpp(imu_int
  "/home/rosbox/control_code/src/imu_int/srv/ImuIntCommand.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/imu_int
)

### Generating Module File
_generate_module_cpp(imu_int
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/imu_int
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(imu_int_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(imu_int_generate_messages imu_int_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rosbox/control_code/src/imu_int/srv/ImuIntCommand.srv" NAME_WE)
add_dependencies(imu_int_generate_messages_cpp _imu_int_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/imu_int/msg/IMU_Int_Data.msg" NAME_WE)
add_dependencies(imu_int_generate_messages_cpp _imu_int_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(imu_int_gencpp)
add_dependencies(imu_int_gencpp imu_int_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS imu_int_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(imu_int
  "/home/rosbox/control_code/src/imu_int/msg/IMU_Int_Data.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/imu_int
)

### Generating Services
_generate_srv_lisp(imu_int
  "/home/rosbox/control_code/src/imu_int/srv/ImuIntCommand.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/imu_int
)

### Generating Module File
_generate_module_lisp(imu_int
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/imu_int
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(imu_int_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(imu_int_generate_messages imu_int_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rosbox/control_code/src/imu_int/srv/ImuIntCommand.srv" NAME_WE)
add_dependencies(imu_int_generate_messages_lisp _imu_int_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/imu_int/msg/IMU_Int_Data.msg" NAME_WE)
add_dependencies(imu_int_generate_messages_lisp _imu_int_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(imu_int_genlisp)
add_dependencies(imu_int_genlisp imu_int_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS imu_int_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(imu_int
  "/home/rosbox/control_code/src/imu_int/msg/IMU_Int_Data.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/imu_int
)

### Generating Services
_generate_srv_py(imu_int
  "/home/rosbox/control_code/src/imu_int/srv/ImuIntCommand.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/imu_int
)

### Generating Module File
_generate_module_py(imu_int
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/imu_int
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(imu_int_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(imu_int_generate_messages imu_int_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rosbox/control_code/src/imu_int/srv/ImuIntCommand.srv" NAME_WE)
add_dependencies(imu_int_generate_messages_py _imu_int_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rosbox/control_code/src/imu_int/msg/IMU_Int_Data.msg" NAME_WE)
add_dependencies(imu_int_generate_messages_py _imu_int_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(imu_int_genpy)
add_dependencies(imu_int_genpy imu_int_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS imu_int_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/imu_int)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/imu_int
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(imu_int_generate_messages_cpp std_msgs_generate_messages_cpp)
add_dependencies(imu_int_generate_messages_cpp imu_int_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/imu_int)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/imu_int
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(imu_int_generate_messages_lisp std_msgs_generate_messages_lisp)
add_dependencies(imu_int_generate_messages_lisp imu_int_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/imu_int)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/imu_int\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/imu_int
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(imu_int_generate_messages_py std_msgs_generate_messages_py)
add_dependencies(imu_int_generate_messages_py imu_int_generate_messages_py)
