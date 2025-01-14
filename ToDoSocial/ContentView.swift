//
//  ContentView.swift
//  ToDoSocial
//
//  Created by Qin Chingis on 1/14/25.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        ZStack {
            Rectangle()
                .frame(width: 300, height: 300)
                .foregroundColor(.black)
                .cornerRadius(30)
            Text("Hello World!")
                .foregroundColor(.white)
        }
        Spacer()
    }
}
#Preview {
    ContentView()
}
