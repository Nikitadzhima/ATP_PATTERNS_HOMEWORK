#include<iostream>

class Command {
  public:
    virtual void execute() = 0;
};

class InputIntNumberCommand : Command {
  public:
    int number = 0;

    void execute() override;
};

class PrintTextCommand : Command {
  public:
    std::string text;

    PrintTextCommand(std::string newText) : text(newText) {}
    void execute() override;
};