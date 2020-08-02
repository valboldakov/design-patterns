cmake_minimum_required(VERSION 3.16)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(strategy strategy/strategy.cpp)
add_executable(observer observer/observer.cpp)
add_executable(decorator decorator/decorator.cpp)
add_executable(factory_method factory_method/factory_method.cpp)
add_executable(abstract_factory abstract_factory/abstract_factory.cpp)
add_executable(singleton singleton/singleton.cpp)
add_executable(command command/command.cpp)
add_executable(adapter adapter/adapter.cpp)
add_executable(facade facade/facade.cpp)
add_executable(template_method template_method/template_method.cpp)
add_executable(iterator iterator/iterator.cpp)
add_executable(composite composite/composite.cpp)
add_executable(state
        state/state.cpp
        state/i_phone_state.h
        state/locked_phone_state.h
        state/unlocked_phone_state.h
        state/phone.h
        state/i_phone.h
        state/unlocked_phone_state.cpp
        state/locked_phone_state.cpp
        state/phone.cpp)
add_executable(proxy proxy/proxy.cpp)
add_executable(bridge bridge/bridge.cpp)
add_executable(builder builder/builder.cpp)
add_executable(chain_of_responsibility chain_of_responsibility/chain_of_responsibility.cpp)
add_executable(flyweight flyweight/flyweight.cpp)
add_executable(interpreter interpreter/interpreter.cpp)
