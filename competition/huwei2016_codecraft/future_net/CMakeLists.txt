# CMake ��Ͱ汾��Ҫ��
cmake_minimum_required(VERSION 3.3)

# ��Ŀ��Ϣ
project(future_net)

# include·��
include_directories(${PROJECT_SOURCE_DIR}/lib)

# ���ÿ�ִ���ļ�����·��
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)

# ����debug�汾
SET(CMAKE_BUILD_TYPE "Debug") 
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# ���ҵ�ǰĿ¼�µ�����Դ�ļ�
# �������Ʊ��浽 DIR_LIB_SRCS ����
aux_source_directory(. DIR_SRCS)

# ���� lib ��Ŀ¼
#add_subdirectory(lib)

# ָ������Ŀ�� 
add_executable(future_net ${DIR_SRCS})

# ���ɴ���·�������ӿ⣬�洢�� FUTURE_NET_LIBRARY ����
find_library(FUTURE_NET_LIBRARY _io ${PROJECT_BINARY_DIR}/../lib)
IF (NOT FUTURE_NET_LIBRARY)
    MESSAGE(FATAL_ERROR "FUTURE_NET_LIBRARY not found")
ENDIF(NOT FUTURE_NET_LIBRARY)

# �������ӿ�
target_link_libraries(future_net ${FUTURE_NET_LIBRARY})
target_link_libraries(future_net pthread)