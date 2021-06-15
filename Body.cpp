#include "Body.h"

Body::Body()
{
    _numParts = MAX_PARTS;
    _hasParts = true;
}

Body::~Body(){}

void Body::removePart()
{
    if (_hasParts)
    {
        _numParts--;
    }
}

bool Body::isDead()
{
    return !_hasParts;
}

string Body::getASCII()
{
    string ascii;

    switch(_numParts)
    {
        case 0:
            ascii =
                "  ||===========|\n"
                "  ||   //      |\n"
                "  ||  //       |\n"
                "  || //      (*_*)\n"
                "  ||//         |\n"
                "  ||            \n"
                "  ||            \n"
                "  ||\n"
                "  ||\n"
                "  ||\n"
                "  ||\n"
                "  ||\n"
                "  ||==========||\n";
            break;
        case 1:
            ascii =
            "  ||===========|\n"
            "  ||   //      |\n"
            "  ||  //       |\n"
            "  || //      (-_-)\n"
            "  ||//         |\n"
            "  ||            \n"
            "  ||            \n"
            "  ||\n"
            "  ||\n"
            "  ||\n"
            "  ||\n"
            "  ||\n"
            "  ||==========||\n";
            break;
        case 2:
            ascii =
            "  ||===========|\n"
            "  ||   //      |\n"
            "  ||  //       |\n"
            "  || //      (-_-)\n"
            "  ||//         |\n"
            "  ||          /\n"
            "  ||         /\n"
            "  ||\n"
            "  ||\n"
            "  ||\n"
            "  ||\n"
            "  ||\n"
            "  ||==========||\n";
            break;
        case 3:
            "  ||===========|\n"
            "  ||   //      |\n"
            "  ||  //       |\n"
            "  || //      (-_-)\n"
            "  ||//         |\n"
            "  ||          / \\\n"
            "  ||         /   \\\n"
            "  ||\n"
            "  ||\n"
            "  ||\n"
            "  ||\n"
            "  ||\n"
            "  ||==========||\n";
            break;
        case 4:
            ascii =
            "  ||===========|\n"
            "  ||   //      |\n"
            "  ||  //       |\n"
            "  || //      (-_-)\n"
            "  ||//         |\n"
            "  ||          /|\\\n"
            "  ||         / | \\\n"
            "  ||           |\n"
            "  ||\n"
            "  ||\n"
            "  ||\n"
            "  ||\n"
            "  ||==========||\n";
            break;
        case 5:
            ascii =
            "  ||===========|\n"
            "  ||   //      |\n"
            "  ||  //       |\n"
            "  || //      (-_-)\n"
            "  ||//         |\n"
            "  ||          /|\\\n"
            "  ||         / | \\\n"
            "  ||           |\n"
            "  ||\n"
            "  ||\n"
            "  ||==========||\n";
            break;
        case 6:
            ascii =
            "  ||===========|\n"
            "  ||   //      |\n"
            "  ||  //       |\n"
            "  || //      (-_-)\n"
            "  ||//         |\n"
            "  ||          /|\\\n"
            "  ||         / | \\\n"
            "  ||           |\n"
            "  ||          / \\\n"
            "  ||         /   \\\n"
            "  ||\n"
            "  ||\n"
            "  ||==========||\n";
            break;
    }

    return ascii;
}