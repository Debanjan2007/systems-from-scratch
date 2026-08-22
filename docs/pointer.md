# Pointers in C

pointer are variable that stores the memory address of another variable. They are used to manipulate data indirectly in memory.

> Pointers are integer type generally, but they can be used to point to any data type. The size of a pointer depends on the architecture of the system (e.g., 32-bit or 64-bit).

# Syntax

```c
    int a = 25 ;
    int *ptr = &a ;
```

In the above example, `ptr` is a pointer to an integer variable `a`. The `&` operator is used to get the address of the variable `a`, and the `*` operator is used to declare a pointer variable. So the `&` is called value at address operator and the `*` is called address of value operator.

## But do we actually need Pointers ?

I guess yes, at first pointers doesn't properly makes sence why do we need to store some memory address and use that to indirectly manipulate the value when we can do it directly but it will be cristal clear with the next sections.

## Memory level

At the memory level the a normal variable and a pointer variable would look like this.

```bash
    a                   a
    │                   |
    ▼                   ▼
  ┌────┐              ┌────┐  
  │ 10 │              │ 10 │  ← address 0x1000
  └────┘              └────┘
                        ▲
                        |
                        | 0x100
                        |
                        *ptr
    
```

So if we try to run a code like this:

```c
    void change(int x) {
    x = 100;
    }
    int main() {
        int a = 10;
        change(a);
        printf("%d", a);
    }
```
It won't output 100 it will be 10 as in the `main` function we are just passing a copy of the variable `a` and it the value has been changed in the `change` scope but if we used pointer it would change the value.


```c
    void change(int *p) {
    *p = 100;
    }
    int main() {
        int a = 10;
        change(&a);
        printf("%d", a);
    }
```

### One better example would be this

Imagine:

```c
    struct User users[1000000];
```

Suppose each User takes 200 bytes.

That's roughly: 200 MB

If you pass the entire thing by value, you'd need to copy a massive amount of data.

Instead:

```c
    void process_users(struct User *users, int count)
```

You pass something like: 8 bytes on a 64-bit system.

The function gets the address of the data, not a copy of the entire dataset.

And at the end most obvious implementation of pointers is Linkedlist.