#pragma once

template<typename T>
shared_ptr<T> New()
{
    return make_shared<T>();
}