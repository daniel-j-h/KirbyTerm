#include <iostream>
#include <ostream>
#include <chrono>
#include <thread>

namespace {

void out(const char* c) { std::cout << c << std::flush; }
void clear(int n) { for (int i = 0; i < n; ++i) out("\b"); }

struct Kirby final {
  Kirby() { out(visual::mid); }

  void left() {
    clear(visual::size);
    out(visual::left);
  }

  void mid() {
    clear(visual::size);
    out(visual::mid);
  }

  void right() {
    clear(visual::size);
    out(visual::right);
  }

private:
  struct visual {
    static const int size;
    static const char* left;
    static const char* mid;
    static const char* right;
  };
};

const int Kirby::visual::size = 7;
const char* Kirby::visual::left = "<(^-^<)";
const char* Kirby::visual::mid = "<(^-^)>";
const char* Kirby::visual::right = "(>^-^)>";


template <std::size_t N, typename Fn>
void seq(Fn fn) {
  std::this_thread::sleep_for(std::chrono::seconds{N});
  fn();
}

template <std::size_t N, typename Fn, typename... Fns>
void seq(Fn fn, Fns... rest) {
  seq<N>(fn);
  seq<N>(rest...);
}

} // ns


int main() {
  Kirby k;

  for (int i = 0; i < 2; ++i)
    seq<1>([&] { k.left(); }, [&] { k.mid(); }, [&] { k.right(); }, [&] { k.mid(); });
}
