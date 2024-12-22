//
// Created by MRSLAVE on 21-Dec-24.
//

void search(int x, po loc) {
    if(loc == nullptr || loc->data == x) {
        here = loc;
        if(here == nullptr) std::cout << "not in";
    } else (loc->data > x) ? search(x, loc->left) : search(x, loc->right);
}

po searchR(int x, po loc) {
    if(loc==nullptr || loc->data == x) return loc;
     else
         if(loc->data > x) return searchR(x, loc->right);
            else return searchR(x, loc->left);
}

po searchHereIT(int x) {
    po loc;
    loc = root;
    while(loc != nullptr && loc->data != x)
        (loc->data > x) ? loc = loc->left : loc = loc->right;
    return loc;
}