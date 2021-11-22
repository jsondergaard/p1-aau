# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "/Users/nichlashjorth/CLionProjects/p1-aau;/Users/nichlashjorth/CLionProjects/p1-aau/cmake-build-debug")
set(CPACK_CMAKE_GENERATOR "Ninja")
set(CPACK_COMPONENTS_ALL "")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/private/var/folders/ft/__0b3g8j6dx50jd7mcn885lr0000gn/T/AppTranslocation/0FD6F429-674A-4B5A-A2F0-914D6D739EB0/d/CLion.app/Contents/bin/cmake/mac/share/cmake-3.21/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "C-Template built using CMake")
set(CPACK_GENERATOR "PackageMaker")
set(CPACK_INSTALL_CMAKE_PROJECTS "/Users/nichlashjorth/CLionProjects/p1-aau/cmake-build-debug;C-Template;ALL;/")
set(CPACK_INSTALL_PREFIX "/usr/local")
set(CPACK_MODULE_PATH "")
set(CPACK_NSIS_DISPLAY_NAME "C-Template 1.0.9")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "C-Template 1.0.9")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OSX_SYSROOT "/Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk")
set(CPACK_OUTPUT_CONFIG_FILE "/Users/nichlashjorth/CLionProjects/p1-aau/cmake-build-debug/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/private/var/folders/ft/__0b3g8j6dx50jd7mcn885lr0000gn/T/AppTranslocation/0FD6F429-674A-4B5A-A2F0-914D6D739EB0/d/CLion.app/Contents/bin/cmake/mac/share/cmake-3.21/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Boilerplate c project with cmake support, CuTest unit testing, and more.")
set(CPACK_PACKAGE_FILE_NAME "C-Template-Mac-1.0.9")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "C-Template 1.0.9")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "C-Template 1.0.9")
set(CPACK_PACKAGE_NAME "C-Template")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Fletcher T. Penney")
set(CPACK_PACKAGE_VERSION "1.0.9")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "My_Project_Version_Patch")
set(CPACK_RESOURCE_FILE_LICENSE "/Users/nichlashjorth/CLionProjects/p1-aau/LICENSE.txt")
set(CPACK_RESOURCE_FILE_README "/private/var/folders/ft/__0b3g8j6dx50jd7mcn885lr0000gn/T/AppTranslocation/0FD6F429-674A-4B5A-A2F0-914D6D739EB0/d/CLion.app/Contents/bin/cmake/mac/share/cmake-3.21/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "/private/var/folders/ft/__0b3g8j6dx50jd7mcn885lr0000gn/T/AppTranslocation/0FD6F429-674A-4B5A-A2F0-914D6D739EB0/d/CLion.app/Contents/bin/cmake/mac/share/cmake-3.21/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "true")
set(CPACK_SOURCE_GENERATOR "TBZ2;TGZ;TXZ;TZ")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/Users/nichlashjorth/CLionProjects/p1-aau/cmake-build-debug/CPackSourceConfig.cmake")
set(CPACK_SOURCE_RPM "OFF")
set(CPACK_SOURCE_TBZ2 "ON")
set(CPACK_SOURCE_TGZ "ON")
set(CPACK_SOURCE_TXZ "ON")
set(CPACK_SOURCE_TZ "ON")
set(CPACK_SOURCE_ZIP "OFF")
set(CPACK_SYSTEM_NAME "Darwin")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "Darwin")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/Users/nichlashjorth/CLionProjects/p1-aau/cmake-build-debug/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
