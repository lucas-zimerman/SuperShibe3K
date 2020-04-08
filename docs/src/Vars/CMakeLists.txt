file(GLOB VARS_SOURCES
    *.h 
    *.cpp 
)
message(STATUS ${VARS_SOURCES})
set(VARS_SOURCES ${VARS_SOURCES})
#add_executable(myapp ${VARS_SOURCES})