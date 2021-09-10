//
// Created by avram on 30.8.21..
//

#ifndef AVRLANG_MODULE_H
#define AVRLANG_MODULE_H

namespace backend {

    void InitializeModuleAndPassManager(void);
    void printModule(bool printIR, std::string outPath);

    class TargetErrorException: public std::exception {
    public:
        TargetErrorException(const std::string& msgstr)
                : msg(msgstr)
        {}
        const char * what() const throw () {
            return msg.c_str();
        }
    private:
        std::string msg;
    };

    class FileException: public std::exception {
    public:
        FileException(const std::string& msgstr)
                : msg(msgstr)
        {}
        const char * what() const throw () {
            return msg.c_str();
        }
    private:
        std::string msg;
    };
}

#endif //AVRLANG_MODULE_H