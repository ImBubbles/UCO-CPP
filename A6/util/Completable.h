#pragma once
#include <functional>

namespace Completable {

    template <typename T, typename G>
    struct CompletableFuture {
        G passthrough;
        T result;
        CompletableFuture(G passthrough) : passthrough(passthrough) {}
        CompletableFuture& onComplete(std::function<T(G)> exec) {
            this->result = exec(passthrough);
            return *this;
        }
        CompletableFuture& onFail(std::function<T(G)> exec) {
            this->result = exec(passthrough);
            return *this;
        }
        T getResult() {
            return this->result;
        }
    };
    
}