######################################################################################
### 1) Set all needed source files for the project
######################################################################################

FILE(GLOB HDRS *.h do)
INSTALL(FILES ${HDRS} DESTINATION include/mylist COMPONENT headers)

FILE(GLOB SOURCES *.c)

SET(SAMPLE_SRCS ${SOURCES} PARENT_SCOPE)

######################################################################################
