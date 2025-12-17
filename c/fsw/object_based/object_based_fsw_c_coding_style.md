# object based

## purpose

- abstraction: public.
- encapsulation: private.

## file structure

- {module}.h: abstraction. public declaration.
- {module}.c: encapsulation. private declaration with static.

## abstraction

```c
// {module}.h

// public type
typedef uint8_t module_id_t;

// public struct
struct module_data
{
    uint8_t data1[4];
    uint32_t data2;
};

// public function
void module_init(module_id_t id);
uint32_t module_get_data_count(module_id_t id);
```

## encapsulation

```c
// {module}.c

// private struct
static struct module_context
{
    struct module_data data_items[MODULE_DATA_COUNT_MAX];
    uint32_t current_data_count;
    bool initialized;
};

// private variable
static struct module_context module_contexts[MODULE_ID_MAX];

// private function
static inline bool module_is_valid_id(module_id_t id)
{
    return (id < MODULE_ID_MAX);
}
```

## tip

- user only knows id, not internal index.
- user knows data structure, not how it is stored.
- user calls simple functions, not complex operations.
- internal state hidden from user.
- internal helper hidden from user.
