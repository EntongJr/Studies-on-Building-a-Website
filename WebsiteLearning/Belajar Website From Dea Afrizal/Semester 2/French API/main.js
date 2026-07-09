console.log("test")

const endpoint = "https://reqres.in/api/users"

fetch(endpoint, {
    method: "POST",
    headers: {
        "Content-Type": "application/json",
    },
    body: JSON.stringify({
        email: "dimsoc@gmail.com",
        firstName: "hehehehehhe",
    }),
})
    .then ((result) => result.json() )
    .then((data) => console.log(data))
