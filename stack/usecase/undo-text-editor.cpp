#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Action
{
    string type;
    string data;

    Action(string type, string data) : type(type), data(data) {}
};

class TextEditor
{
private:
    stack<Action> actions;

public:
    void performAction(const Action &action)
    {
        cout << "Perform action: " << action.type << " '" << action.data << "'" << endl;
        actions.push(action);
    }

    void undoAction()
    {
        if (actions.empty())
        {
            cout << "No actions to undo." << endl;
            return;
        }
        Action action = actions.top();
        actions.pop();
        cout << "Undoing action: " << action.type << " '" << action.data << "'" << endl;
    }
};

int main()
{
    TextEditor editor;
    editor.performAction(Action("add", "Hello 1"));
    editor.performAction(Action("add", "Hello 2"));
    editor.performAction(Action("delete", "Hello 1"));

    editor.undoAction();
    editor.undoAction();
    return 0;
}