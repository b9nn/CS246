// reinterpret cast forces the cast!

// unsafe, can easily result in undefined behavior

student elon;
turtle *t = reinterpret_cast<turtle*>(elon);
    // student becomes a tutrle (undefined)
    