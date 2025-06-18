# log.h

Logging library implemented in C programming language for **educational and
recreational purposes.**

## TO DO

- External and Dynamic Configuration
- Custom Log Formatting
- Improve Error Handling
- Refactor for Code consistency
- Performance and Efficiency
- Security Enhancement
- Integrate with logging tools
- Testing and Validation
- Cross-platform logging

## Usage

### Installation

Clone the repository.

```shell
git clone git@github.com:ragibasif/log.h.git
cp log.h/log.h /path/to/your/project/include/
cp log.h/log.c /path/to/your/project/src/
```

### Include in you program

```c
#include "log.h"
```

### Build the program

The library uses `pthread.h` to ensure thread safety. Thus, `-pthread` must be
passed to the linker.

```shell
gcc -pthread -o app main.c log.c
```

## Contributing

1. Fork the repository
2. Create a new branch (`git checkout -b feature/feature-name`)
3. Make your changes and commit (`git commit -am 'Add new feature'`)
4. Push to your fork (`git push origin feature/feature-name`)
5. Open a pull request

## License

This project is licensed under the **MIT license**. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

- [Creating a Robust Logging System in C by Vitor Lobo](https://dev.to/scovl/creating-a-robust-logging-system-in-c-2fg6)
