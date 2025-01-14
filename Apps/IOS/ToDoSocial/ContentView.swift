import SwiftUI
import FirebaseFirestore

struct ContentView: View   {
    
    let db = Firestore.firestore()
    
    var body: some View    {
        Button("Add user") {
            addUser()
        }
    }
    func addUser() {
        let usersRef = db.collection("users")
        let newUser: [String: Any] = [
            "name": "John Doe",
            "password": "securePassword123"
        ]
        usersRef.addDocument(data: newUser) { error in
            if let error = error {
                print("Ошибка добавления документа: \(error.localizedDescription)")
            } else {
                print("Документ успешно добавлен!")
            }
        }
    }
}
#Preview {
    ContentView()
}
