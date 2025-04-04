<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>C Language Editor</title>
    <style>
        body {
            font-family: Consolas, "Courier New", monospace;
            background-color: #1e1e1e;
            color: #dcdcdc;
            margin: 0;
            padding: 0;
            height: 100vh;
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .container {
            width: 80%;
            max-width: 1000px;
            height: 80%;
            background-color: #2d2d2d;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.5);
            padding: 20px;
        }

        h2 {
            color: #4caf50;
            text-align: center;
            margin-bottom: 20px;
        }

        textarea {
            width: 100%;
            height: 300px;
            background-color: #1e1e1e;
            color: #dcdcdc;
            font-size: 16px;
            line-height: 1.5;
            border: 1px solid #444;
            padding: 10px;
            border-radius: 8px;
            resize: none;
            box-sizing: border-box;
            font-family: Consolas, "Courier New", monospace;
            white-space: pre-wrap;
            word-wrap: break-word;
            overflow: auto;
        }

        textarea:focus {
            outline: none;
            border-color: #4caf50;
        }

        .output-container {
            margin-top: 20px;
            background-color: #333;
            padding: 10px;
            border-radius: 8px;
        }

        .output {
            color: #ffcc00;
            white-space: pre-wrap;
        }

        button {
            background-color: #4caf50;
            color: white;
            padding: 10px 20px;
            border: none;
            border-radius: 8px;
            cursor: pointer;
            font-size: 16px;
            margin-top: 20px;
            width: 100%;
        }

        button:hover {
            background-color: #45a049;
        }
    </style>
</head>
<body>
    <div class="container">
        <h2>C Language Editor with Compiler</h2>
        <textarea id="codeArea" placeholder="Write your C code here..."></textarea>
        <button onclick="runCode()">Run Code</button>

        <div class="output-container" id="outputContainer" style="display:none;">
            <h3>Output:</h3>
            <pre id="output" class="output"></pre>
        </div>
    </div>

    <script>
        const clientId = "8bd547467b6db7fd7a15e99be5ee40fb";  // Replace with your JDoodle Client ID
        const clientSecret = "199e9787e006edf5d9fec5b16a8b901fc4f1ebfbb7db9ffbe9ed8ec97c719859";  // Replace with your JDoodle Client Secret
       
       

        function runCode() {
            const code = document.getElementById('codeArea').value;

            // Show loading spinner or some message
            document.getElementById('output').textContent = "Compiling...";
            document.getElementById('outputContainer').style.display = "block";

            const requestData = {
                script: code,
                language: "c",
                versionIndex: "0", // Use the default C version (C99)
                clientId: clientId,
                clientSecret: clientSecret
            };

            fetch("https://api.jdoodle.com/v1/execute", {
                method: "POST",
                headers: {
                    "Content-Type": "application/json"
                },
                body: JSON.stringify(requestData)
            })
            .then(response => response.json())
            .then(data => {
                // Display the output from JDoodle API
                if (data.output) {
                    document.getElementById('output').textContent = data.output;
                } else {
                    document.getElementById('output').textContent = "Error: " + data.error;
                }
            })
            .catch(error => {
                document.getElementById('output').textContent = "Error: Unable to compile the code.";
            });
        }
    </script>
</body>
</html>
