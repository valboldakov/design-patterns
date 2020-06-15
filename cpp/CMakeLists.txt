cmake_minimum_required(VERSION 3.16)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(strategy strategy/strategy.cpp)
add_executable(observer observer/observer.cpp)
add_executable(decorator decorator/decorator.cpp)
add_executable(factory_method factory_method/factory_method.cpp)
add_executable(abstract_factory abstract_factory/abstract_factory.cpp)
