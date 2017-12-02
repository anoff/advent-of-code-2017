module checksum

let lineStringToIntArray (lineString : string) =
        lineString.Split '\t'
        |> Array.map int

let lineMaxDiff (elements : array<int>) =
    (elements |> Array.max) - (elements |> Array.min)

let lineDivisibleElements (elements : array<int>) =
    let mutable fraction = 0
    for n in elements do
        let divisor =
            elements
            |> Array.filter (fun elem -> elem <> n)
            |> Array.filter (fun elem -> n % elem = 0)

        if divisor.Length > 0 then
            fraction <- n / divisor.[0]
    fraction

[<EntryPoint>]
let main args = 
//    args.Length |> printfn "Length: %d"
//    args |> printfn "Items: %A"
    let inputString = args.[0]
    let mutable totalSum = 0
    let lines = inputString.Split '\n'
//    lines.Length |> printfn "Lines: %d"

    let mutable lineFunction = lineMaxDiff

    if args.Length > 1 && args.[1] = "divisible" then
        lineFunction <- lineDivisibleElements

    for line in lines do
        let lineElements = lineStringToIntArray(line)
        totalSum <- totalSum + lineFunction(lineElements)
    printfn "Checksum: %d" totalSum
    0