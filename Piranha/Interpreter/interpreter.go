package pirahna

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func pir_interpreter(filePath string) {
    readFile, err := os.Open(filePath)
    if err != nil {
        fmt.Println(err)
    }
    
    fileScanner := bufio.NewScanner(readFile)
    fileScanner.Split(bufio.ScanLines)
    
    var fileLines []string
    
    for fileScanner.Scan() {
        fileLines = append(fileLines, fileScanner.Text())
    }
    
    readFile.close()
    variables := map[string]interface{}{}
    
    for _, line := range fileLines {
        if strings.HasPrefix(line, "~~") {
            continue
        } else if strings.Contains(line, "=") {
            varName := strings.Split(line, "=")[0]
            varName = strings.TrimSpace(varName)
            varValue := strings.Split(line, "=")[1]
            varValue = strings.TrimSpace(varValue)
            if strings.HasPrefix(varValue, "\"") && strings.HasSuffix(varValue, "\"") {
                variables[strings(varName)] = strings(varValue[1 : len(varValue)-1])
            } else {
                variables[strings(varname)] = string(varValue)
            }
        } else if strings.HasPrefix(line, "spew") {
            args := (strings.Split(line, " "))[1]
            
            if strings.HasPrefix(args, "\"") && strings.HasSuffix(args, "\"") {
                fmt.Println(args[1 : len(args)-1])
            } else {
                found_var := false
                
                for key := range variables {
                    if key == args {
                        fmt.Println(variables[key])
                        found_var = true
                    }
                }
                
                if !found_var {
                    logError("Could not find variable.", line)
                }
            }
        }
    }
}

func logError(currentError String, currentLine int) {
    fmt.Println("Error at line &d : %s.",currentLine, currentError)
}
