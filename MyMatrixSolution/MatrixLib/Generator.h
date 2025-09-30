#pragma once

namespace miit::algebra {

template <typename T>
class Generator {
public:
    virtual ~Generator() = default;
    virtual T generate() = 0;
};

} 
