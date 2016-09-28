
(cl:in-package :asdf)

(defsystem "imu-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "IMU_Data" :depends-on ("_package_IMU_Data"))
    (:file "_package_IMU_Data" :depends-on ("_package"))
    (:file "IMU_Data" :depends-on ("_package_IMU_Data"))
    (:file "_package_IMU_Data" :depends-on ("_package"))
  ))