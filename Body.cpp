#include "Body.h"

Body::Body()
{
    _condition = UNHARMED;
}

Body::~Body(){}

void Body::removePart()
{
    // If not dead, reduce bodily condition
    if (!isDead())
    {
        _condition--;
    }
}

void Body::setFree()
{
    _condition = FREED;
}

bool Body::isDead()
{
    return _condition == DEAD;
}

void Body::restoreBody()
{
    _condition = UNHARMED;
}

int Body::getCondition()
{
    return _condition;
}

void Body::displayASCII() const
{
    switch(_condition)
    {
        case DEAD:
            cout <<
                "||===========|\n"
                "||   //      |\n"
                "||  //       |\n"
                "|| //      (*_*)\n"
                "||//         |\n"
                "||            \n"
                "||            \n"
                "||\n"
                "||\n"
                "||\n"
                "||\n"
                "||\n"
                "||==========||" << endl;
            break;
        case ONE_PART:
            cout <<
            "||===========|\n"
            "||   //      |\n"
            "||  //       |\n"
            "|| //      (-_-)\n"
            "||//         |\n"
            "||            \n"
            "||            \n"
            "||\n"
            "||\n"
            "||\n"
            "||\n"
            "||\n"
            "||==========||" << endl;
            break;
        case TWO_PARTS:
            cout <<
            "||===========|\n"
            "||   //      |\n"
            "||  //       |\n"
            "|| //      (-_-)\n"
            "||//         |\n"
            "||          /\n"
            "||         /\n"
            "||\n"
            "||\n"
            "||\n"
            "||\n"
            "||\n"
            "||==========||" << endl;
            break;
        case THREE_PARTS:
            cout <<
            "||===========|\n"
            "||   //      |\n"
            "||  //       |\n"
            "|| //      (-_-)\n"
            "||//         |\n"
            "||          / \\\n"
            "||         /   \\\n"
            "||\n"
            "||\n"
            "||\n"
            "||\n"
            "||\n"
            "||==========||" << endl;
            break;
        case FOUR_PARTS:
            cout <<
            "||===========|\n"
            "||   //      |\n"
            "||  //       |\n"
            "|| //      (-_-)\n"
            "||//         |\n"
            "||          /|\\\n"
            "||         / | \\\n"
            "||           |\n"
            "||\n"
            "||\n"
            "||\n"
            "||\n"
            "||==========||" << endl;
            break;
        case FIVE_PARTS:
            cout <<
            "||===========|\n"
            "||   //      |\n"
            "||  //       |\n"
            "|| //      (-_-)\n"
            "||//         |\n"
            "||          /|\\\n"
            "||         / | \\\n"
            "||           |\n"
            "||          /\n"
            "||         /\n"
            "||\n"
            "||\n"
            "||==========||" << endl;
            break;
        case UNHARMED:
            cout <<
            "||===========|\n"
            "||   //      |\n"
            "||  //       |\n"
            "|| //      (-_-)\n"
            "||//         |\n"
            "||          /|\\\n"
            "||         / | \\\n"
            "||           |\n"
            "||          / \\\n"
            "||         /   \\\n"
            "||\n"
            "||\n"
            "||==========||" << endl;
            break;
        case FREED:
            cout <<
                "||===========|\n"
                "||   //\n"
                "||  //\n"
                "|| //"
                "||//"
                "||"
                "||              (-_-)\n"
                "||              \\ | /\n"
                "||               \\|/\n"
                "||                |\n"
                "||                |\n"
                "||               / \\\n"
                "||==========||  /   \\" << endl;
            break;
    }
}