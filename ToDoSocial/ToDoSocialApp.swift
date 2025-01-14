import SwiftUI

@main
struct ToDoListApp: App {
    var body: some Scene {
        WindowGroup {
            ContentView()
        }
    }
}

struct MainViewToDoListApp: View {
    var body: some View {
        ContentView()
    }
}

#Preview {
    MainViewToDoListApp()
}
