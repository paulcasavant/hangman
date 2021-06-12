//
// Created by Paul Casavant on 6/10/21.
//

#include "Body.h"

Body::Body(){}

Body::~Body(){}

bool Body::removePart() const
{
    return true;
}

void Body::display()
{
    string asciiBody =
        "  ||===========||\n"
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

    cout << asciiBody << endl;
}