# procedure module layer

## purpose

- define dependency rules between procedure layer and module layer.

## effect

- prevent circular dependency.
- module count shows abstraction level.
- procedure count shows workflow complexity.
- module/procedure ratio shows design focus.

## layer

- procedure (p0, p1, p2, ...): top-down. p0 is top.
- module (m0, m1, m2, ...): bottom-up. m0 is bottom.

## component

- layer contains components.
- procedure component: verb. (init, loop, interrupt)
- module component: noun. (cpu, ram, rom)

## dependency rule

1. pX can include pY. (Y > X)
2. mX can include mY. (Y < X)
3. pX can include mY. (any Y)
4. mX cannot include pY. (any Y)

```mermaid
graph LR
    P0[p0] --> P1[p1]
    P1 --> P2[p2]
    P2 --> PN[p...]
    MN[m...] --> M1[m1]
    M1 --> M0[m0]
    P0 --> MN
    P0 --> M1
    P0 --> M0
    P1 --> MN
    P1 --> M1
    P1 --> M0
    P2 --> MN
    P2 --> M1
    P2 --> M0
    PN --> MN
    PN --> M1
    PN --> M0
```

## directory structure

```
p0/
    {verb}/
p1/
    {verb}/
p.../
    {verb}/
m0/
    {noun}/
m1/
    {noun}/
m.../
    {noun}/
```

```mermaid
graph TD
    A[p0] --> B["{verb}"]
    C[p1] --> D["{verb}"]
    E["p..."] --> F["{verb}"]
    G[m0] --> H["{noun}"]
    I[m1] --> J["{noun}"]
    K["m..."] --> L["{noun}"]
    
    A -.-> C -.-> E -.-> K -.-> I -.-> G
```
